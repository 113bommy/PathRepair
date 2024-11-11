n = int(input())
idx___people_nr = [int(x) for x in input().split()]
temp = [max(0, idx___people_nr[i] - i) for i in range(n)]
circles_nr = (min(temp) + 1) // n
idx___nice_people_nr = [x - circles_nr * n for x in idx___people_nr]
for i in range(n):
    if idx___nice_people_nr[i] <= i:
        print(i + 1)
        quit()