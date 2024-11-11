N = input()
print("YNeos"[int(N)%sum(int(n)for n in N)&1::2])