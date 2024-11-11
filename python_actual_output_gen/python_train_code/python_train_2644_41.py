n, m = input().split()
if(m=="0"):
    print(0)
else:
    print(min(int(m), int(n)-int(m)))