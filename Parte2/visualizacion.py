import matplotlib.pyplot as plt

DISK_SIZE = 5000

def fcfs(requests, head):
    order = []
    order.append(head)

    i = 0
    while i < len(requests):
        order.append(requests[i])
        i += 1

    return order

def scan(requests, head):
    order = []
    order.append(head)

    lower = []
    higher = []

    i = 0
    while i < len(requests):
        if requests[i] < head:
            lower.append(requests[i])
        else:
            higher.append(requests[i])
        i += 1

    lower.sort(reverse=True)
    higher.sort()

    i = 0
    while i < len(higher):
        order.append(higher[i])
        i += 1

    order.append(DISK_SIZE - 1)

    i = 0
    while i < len(lower):
        order.append(lower[i])
        i += 1

    return order

def cscan(requests, head):
    order = []
    order.append(head)

    lower = []
    higher = []

    i = 0
    while i < len(requests):
        if requests[i] < head:
            lower.append(requests[i])
        else:
            higher.append(requests[i])
        i += 1

    lower.sort()
    higher.sort()

    i = 0
    while i < len(higher):
        order.append(higher[i])
        i += 1

    order.append(DISK_SIZE - 1)
    order.append(0)

    i = 0
    while i < len(lower):
        order.append(lower[i])
        i += 1

    return order

def total_movement(order):
    total = 0

    i = 1
    while i < len(order):
        total += abs(order[i] - order[i - 1])
        i += 1

    return total

def plot_head_movement(order, title):
    x = []

    i = 0
    while i < len(order):
        x.append(i)
        i += 1

    plt.figure()
    plt.plot(x, order, marker='o')
    plt.title(title)
    plt.xlabel("Order of serviced requests")
    plt.ylabel("Cylinder number")
    plt.grid(True)
    plt.show()

def plot_comparison(names, movements):
    plt.figure()
    plt.bar(names, movements)
    plt.title("Performance Comparison")
    plt.xlabel("Disk Scheduling Algorithm")
    plt.ylabel("Total Head Movement")
    plt.grid(axis='y')
    plt.show()

requests = [2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681]
head = 2150

fcfs_order = fcfs(requests, head)
scan_order = scan(requests, head)
cscan_order = cscan(requests, head)

fcfs_movement = total_movement(fcfs_order)
scan_movement = total_movement(scan_order)
cscan_movement = total_movement(cscan_order)

print("FCFS total movement:", fcfs_movement)
print("SCAN total movement:", scan_movement)
print("C-SCAN total movement:", cscan_movement)

plot_head_movement(fcfs_order, "FCFS Head Movement")
plot_head_movement(scan_order, "SCAN Head Movement")
plot_head_movement(cscan_order, "C-SCAN Head Movement")

names = ["FCFS", "SCAN", "C-SCAN"]
movements = [fcfs_movement, scan_movement, cscan_movement]

plot_comparison(names, movements)