N, B = map(int, input().split())
sequence = [int(num) for num in input().split()][0:N]

odd = even = 0
bit = []
res=0
for i in range(N):
    if sequence[i] % 2 == 0:
        even +=  1
    else:
        odd +=  1
    if even == odd and len(sequence[0:i])<N-1 :
        bit += [0]
        bit[-1]=sequence[i + 1] - sequence[i]
bit.sort()
for i in range(len(bit)):
    if bit[i]<=B:
        res +=1
        B -=  bit[i]
    else:
        break

print(res)