def finish():
    print('NO')
    exit()

N = int(input())
cnt = 0
vec = -1
for i in range(N):
    w = input()
    if  w == 'A':
        #if vec == -1 and cnt != 0:
        #    finish()
        cnt += 1
        vec = 1
    else:
        if cnt == 0:
            finish()

        cnt -= 1
        vec = -1
if cnt != 0:
    finish()
print('YES')

