n = int(input())
A = list(map(int, input().split()))
q = int(input())
m = list(map(int, input().split()))

sum_list = []
for i in range(n**2):
    b = '{0:0{1}b}'.format(i, n)
    temp = []
    for j in range(n):
        if b[j] == '1':
            temp.append(A[j])
    sum_list.append(sum(temp))


for k in m:
    print('yes' if k in sum_list else 'no')