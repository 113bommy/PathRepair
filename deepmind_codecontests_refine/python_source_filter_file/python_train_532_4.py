"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
"""""""""""""""""""""""""""""""""""""""""""""
#inp = open("spaceship.in", "r"); input = inp.readline; out = open("spaceship.out", "w"); print = out.write
TN = 1


# ===========================================
  
  
def solution():
    n, m, k = map(int, input().split())
    p = list(map(int, input().split()))
    s = list(map(int, input().split()))
    c = list(map(int, input().split()))
    lst = [[] for i in range(m)]
    izbr = []
    ans = 0
    for i in range(n):
        lst[s[i]-1].append(p[i])
    for i in range(m):
        izbr.append(max(lst[i]))
    for i in range(k):
        if c[i] not in izbr: ans += 1
    print(ans)


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
#inp.close()
#out.close()