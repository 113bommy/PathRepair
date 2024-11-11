W, H, x, y = map(int, input().split())
print(f"{W*H/2} {int(W==x*2 and H==y*2)}")