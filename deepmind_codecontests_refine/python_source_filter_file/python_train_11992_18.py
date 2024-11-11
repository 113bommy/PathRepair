n = int(input())
lis = [a for  a in input()]

ones = lis.count('n')
zeroes = lis.count('z')

ans = '1'*ones + '0'*zeroes

print(ans)
