t = int(input())

for i in range(t):
        x = sorted(map(int, input().split()))
        if x[2] != x[1]:
                print("NO")
        else:
                print(f"YES\n{x[2]} {x[2]} {x[0]}")
