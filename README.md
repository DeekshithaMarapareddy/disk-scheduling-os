# Disk Scheduling Algorithms (OS Project)

##  Description
This project implements and compares different disk scheduling algorithms used in Operating Systems.

##  Algorithms Implemented
- FCFS (First Come First Serve)
- SSTF (Shortest Seek Time First)
- SCAN (Elevator Algorithm)
- C-SCAN (Circular SCAN)
- LOOK
- C-LOOK

##  Objective
To compare algorithms based on total head movement and performance.

##  How to Run

```bash
gcc disk_scheduling.c -o disk
./disk
 Example Input

Requests: 98 183 37 122 14 124 65 67
Head: 53
Disk Size: 200

 Output

Displays:

Order of execution
Total head movement for each algorithm
 Conclusion

Algorithms like LOOK and C-LOOK generally perform better by reducing unnecessary head movement.

---
```
