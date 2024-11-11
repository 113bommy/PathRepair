def inter(s11,s12,s21,s22):
    return max(0,min(s12,s22) - max(s11,s21) + 1)
n, k = map(int,input().split())
ai = list(map(int,input().split()))
anss = [0] * n
for i in range(n):
    if ai[i] == 0:
        s11 = 0
        s12 = n-1
        s21 = i-k
        s22 = i+k
        anss[i] = inter(s11,s12,s21,s22)
    else:
        num = ai[i]-1
        s11 = num - k
        s12 = num + k
        s21 = i-k
        s22 = i+k
        temp = inter(s11,s12,s21,s22)
        s11 = n
        s12 = 2*n
        s21 = i-k
        s22 = i+k
        temp2 = inter(s11,s12,s21,s22)
        s11 = num - k
        s12 = num + k
        s21 = n
        s22 = 2*n
        temp3 = inter(s11,s12,s21,s22)
        s11 = -n
        s12 = 0
        s21 = i-k
        s22 = i+k
        temp4 = inter(s11,s12,s21,s22)
        anss[i] = anss[num] + 2 * k + 1 - temp - temp2
print(" ".join(map(str,anss)))
