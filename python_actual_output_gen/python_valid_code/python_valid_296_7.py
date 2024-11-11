"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
"""""""""""""""""""""""""""""""""""""""""""""
#inp = open("lepus.in", "r"); input = inp.readline; out = open("lepus.out", "w"); print = out.write
TN = 1


# ===========================================
  
  
def solution():
    n, t = map(int, input().split())
    a = list(map(int, input().split()))
    cur = t
    for i in range(n):
        cur -= 86400-a[i]
        if not cur:
            print(i+1)
            break


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
#inp.close()
#out.close()