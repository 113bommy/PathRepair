N = int(input())
print("YNeos"[N not in [a+b for a in range(4,N+1,4) for b in range(7,N+1,7)]::2])