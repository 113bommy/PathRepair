# --- Input ---
# [Number of pages of book (1 <= n <= 1000)
# [i-th day's reading budget] for i from 1 to 7

# --- Task ---
# If the reading schedule is constant across weeks,
# which day will he finish the book?
# Note: 1 = mon, 2 = tue, 3 = wed, etc...

if __name__ == '__main__':
    print('', end='')

num_pages = int(input())
day_number = 0
sched_str = input().strip()
schedule = [int(x) for x in sched_str.split(' ')]
while True:
    day = schedule[day_number % 7]
    day_number += 1
    num_pages -= day
    if num_pages <= 0:
        break
ans = day_number % 7
print(ans if not ans == 7 else 0)
