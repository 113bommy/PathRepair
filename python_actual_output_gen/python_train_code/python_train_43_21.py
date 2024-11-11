N = int(input().strip())
S = str(input().strip())

st = False
for idx in range(N-1):
    if ord(S[idx])>ord(S[idx+1]):
        print('YES')
        print(idx, idx+1)
        st=True
        break
if st==False:
    print('NO')