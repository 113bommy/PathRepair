import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N,*P = map(int,read().split())

INF = N+100
P = [INF,INF] + P + [INF,INF]

x_to_i = [0] * (INF+1)
for i,x in enumerate(P):
    x_to_i[x] = i

"""
・小さい方から埋めていく。
・埋めた位置に対して、「連結成分の左端」「連結成分の右端」を持つ
・区間の両端については、正しい値が入っている状態を保つ
"""

left = list(range(N+4))
right = list(range(N+4))
filled = [False] * (N+4)

answer = 0
for x,i in enumerate(x_to_i[1:N+1],1):
    filled[i] = True
    L = left[i-1] if filled[i-1] else i
    R = right[i+1] if filled[i+1] else i
    right[L] = R; left[R] = L
    # 自身より大きい場所。左右に2つずつ。
    c = i
    b = L-1; d = R+1
    a = left[L-3] if filled[L-2] else L-2
    e = right[R+3] if filled[R+2] else R+2
    coef = 0
    if b>=2: # 最大値をb,cとして選ぶ
        coef += (b-a)*(d-c)
    if d<=N+1:
        coef += (e-d)*(c-b)
    answer += x*coef

print(answer)