n, time ,oven ,newo = map(int,input().split())
print("YES" if (newo/time + 1)*oven < n else "NO")
