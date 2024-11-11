import sys
import math

info = [int(x) for x in sys.stdin.readline().split()]
n_stations, n_children = info[0], info[1]

min_sum = 0
for i in range(n_stations):
    values = [int(x) for x in sys.stdin.readline().split()]
    initial_temp, temp_limit, cost_demanded, bus_price = \
      values[0], values[1], values[2], values[3]

    if temp_limit - initial_temp > 0:
        n_buses_no_penalty = int(math.ceil(n_children / (temp_limit - initial_temp)))
        if n_buses_no_penalty * bus_price <= bus_price + n_children * cost_demanded:
            min_sum += n_buses_no_penalty * bus_price
            print("No penalty", n_buses_no_penalty, "price", bus_price)
        else:
            min_sum += bus_price + n_children * cost_demanded
            print("Penalty", bus_price + n_children * cost_demanded)
    else:
        min_sum += bus_price + n_children * cost_demanded

print(min_sum)
