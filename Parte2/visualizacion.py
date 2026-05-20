import matplotlib.pyplot as plt
import csv

orders = {}

with open("results.csv", "r") as file:

    reader = csv.reader(file)

    next(reader)

    for row in reader:

        algorithm = row[0]

        cylinder = int(row[2])

        if algorithm not in orders:

            orders[algorithm] = []

        orders[algorithm].append(cylinder)


def total_movement(order):

    total = 0

    i = 1

    while i < len(order):

        total += abs(order[i] - order[i - 1])

        i += 1

    return total


def plot_head_movement(order,
                       title):

    x = []

    i = 0

    while i < len(order):

        x.append(i)

        i += 1

    plt.figure()

    plt.plot(x,
             order,
             marker='o')

    plt.title(title)

    plt.xlabel(
        "Order of serviced requests"
    )

    plt.ylabel(
        "Cylinder number"
    )

    plt.grid(True)

    plt.show()


def plot_comparison(names,
                    movements):

    plt.figure()

    plt.bar(names,
            movements)

    plt.title(
        "Performance Comparison"
    )

    plt.xlabel(
        "Disk Scheduling Algorithm"
    )

    plt.ylabel(
        "Total Head Movement"
    )

    plt.grid(axis='y')

    plt.show()


fcfs_order = orders["FCFS"]

scan_order = orders["SCAN"]

cscan_order = orders["CSCAN"]


fcfs_movement = total_movement(fcfs_order)

scan_movement = total_movement(scan_order)

cscan_movement = total_movement(cscan_order)


plot_head_movement(
    fcfs_order,
    "FCFS Head Movement"
)

plot_head_movement(
    scan_order,
    "SCAN Head Movement"
)

plot_head_movement(
    cscan_order,
    "C-SCAN Head Movement"
)


names = [
    "FCFS",
    "SCAN",
    "C-SCAN"
]

movements = [
    fcfs_movement,
    scan_movement,
    cscan_movement
]

plot_comparison(
    names,
    movements
)