#include <iostream>
#include <vector>
#include "fcfs_scheduler.h"
#include "task.h"
#include <cpp-httplib/httplib.h>
#include <nlohmann/json.hpp>

using namespace httplib;
using json = nlohmann::json;

std::vector<Task> tasks = {
    Task(1, 0, 5, 2),
    Task(2, 2, 3, 1),
    Task(3, 4, 1, 3)
};

void runScheduler() {
    FCFSScheduler scheduler;
    scheduler.schedule(tasks);
}

json getTasksAsJson() {
    json j;
    for (const auto& task : tasks) {
        j.push_back({
            {"id", task.id},
            {"arrival_time", task.arrival_time},
            {"burst_time", task.burst_time},
            {"priority", task.priority},
            {"remaining_time", task.remaining_time},
            {"state", task.state}
        });
    }
    return j;
}

int main() {
    runScheduler();

    Server svr;
    svr.Get("/schedule", [](const Request& req, Response& res) {
        res.set_content(getTasksAsJson().dump(), "application/json");
    });

    std::cout << "Server started at http://localhost:8080\n";
    svr.listen("localhost", 8080);
    return 0;
}
