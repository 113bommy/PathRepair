n,k,M = map(int, input().split(' '))
t = map(int, input().split(' '))

st_but_long = list(sorted(t))
max_point = 0

for finished_tasks in range(n+1):
    iteration_point = 0
    remaining_minutes = M

    remaining_minutes -= (sum(st_but_long) * finished_tasks)
    iteration_point += ((k+1) * finished_tasks) if (finished_tasks > 0 and remaining_minutes >= 0) else 0

    # print (f"finished_tasks {finished_tasks}")
    # print (f"remaining minutes {remaining_minutes}")
    # print (f"iteration_point {iteration_point}")

    for subtask in range(k-1):
        if remaining_minutes > 0:
            total_accomodated_columns = min(n - finished_tasks, (remaining_minutes // st_but_long[subtask]))

            remaining_minutes -= (total_accomodated_columns * st_but_long[subtask])
            iteration_point += total_accomodated_columns if (remaining_minutes > 0) else 0

    # print (f"iteration_point {iteration_point}")
    max_point = max(max_point, iteration_point)

print (max_point)