#Problem C
n, m = map(int, input().split())
L = [list(map(int,input().split())) for _ in range(m)] #s_i, c_i

for i in range(10**n): #ぜんぶやる
    st = str(i)
    if len(st) == n and all(st[s-1] == str(c) for s, c in L): #長さ＝桁数がiで、かつ全てにおいて[s=c]すなわち[stのs番目の文字＝c]となるとき
        print(i)
        exit()

print(-1)