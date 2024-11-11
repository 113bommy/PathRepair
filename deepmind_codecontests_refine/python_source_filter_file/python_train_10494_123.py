N, A, B, C, D = map(int, input().split())
S = input()

if S[A-1:C-1].find('##') != -1 or S[B-1:D-1].find('##') != -1:
    print('No')
    exit()

ans = 'Yes'
if C > D and S[B-2:D-1].find('...') == -1:
    ans = 'No'
print(ans)
