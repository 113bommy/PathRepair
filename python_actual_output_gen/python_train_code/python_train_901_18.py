H, W, N = [int(input()) for _ in range(3)]
print(min((N+H-1)//H, (W+W-1)//W))
