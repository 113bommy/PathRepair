def cal(x,num,xx):
    y = str(x)
    nm = str(num)
    cnt = 0
    br = str(num)
    gr = ""
    for z in range(len(y)):
        if z!=(len(y)-1):
            if y[z] in br:
                c = br.index(y[z])
                cnt += c
                br = br[c+1:]
            else:
                cnt+=len(br)+1
                br = ""
        else:
            if y[z] in br:
                cnt += len(br) -1
            else:
                cnt += len(br) + 1
        if cnt>xx:
            return cnt
    return cnt

arr = [2 ** x for x in range(50)]

for _ in range(int(input())):
    num = input()
    if int(num) in arr:
        print(0)
        continue
    ct = len(num)+1
    for x in arr:
        p = cal(x,num,ct)
        if(p<ct):
            ct=p

    print(ct)