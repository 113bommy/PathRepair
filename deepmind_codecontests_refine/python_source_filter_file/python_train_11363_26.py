"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
"""""""""""""""""""""""""""""""""""""""""""""
#inp = open("lepus.in", "r"); input = inp.readline; out = open("lepus.out", "w"); print = out.write
TN = 1


# ===========================================

  
def solution():
    n = int(input())
    ans = [0, 0, 0, 6, 18]+[0 for i in range(n)]
    for i in range(5, n+1):
        ans[i] = ans[i-1] + i*(i+1)
    print(ans[n])


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
#inp.close()
#out.close()