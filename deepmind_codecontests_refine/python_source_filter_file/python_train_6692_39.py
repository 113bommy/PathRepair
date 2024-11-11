tc = int(input())
for t in range(tc):
    n = input()
    ans = (int(n[0])-1)*10+(len(n)-1)*len(n)+1
    print(ans)