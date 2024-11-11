count = int(input())
shows = []
impossible = False
showing = 0

for i in range(count):
    show = input().split(' ')
    shows.append([int(show[0]), 1])
    shows.append([int(show[1]) + 1, -1])
shows.sort(key=lambda iterableShow: iterableShow[0] * 3 + iterableShow[1])

for i in range(count * 2):
    showing += shows[i][1]
    if showing > 2:
        print("NO")
        impossible = True
        break

if not impossible:
    print("YES")
