// scripts.js
document.addEventListener('DOMContentLoaded', () => {
    fetch('/scheduler-results')
        .then(response => response.json())
        .then(data => {
            const outputDiv = document.getElementById('scheduler-output');
            data.forEach(process => {
                const processDiv = document.createElement('div');
                processDiv.textContent = `Process ID: ${process.pid}, Arrival Time: ${process.arrival_time}, Burst Time: ${process.burst_time}`;
                outputDiv.appendChild(processDiv);
            });
        });
});
