def main():
    n = int(input())
    s = input()
    lamps = []
    for i in range(n):
        a,b = map(int,input().split())
        lamps.append((a,b))

    on = {}
    max_val = 0
    for i in range(n):
        if s[i] == '1':
            count = 1
        else:
            count = 0

        a,b = lamps[i][0],lamps[i][1]
        if s[i] == '1':
            for i in range(1,b):
                if i not in on.keys():
                    on[i] = 1
                    max_val = max(max_val,1)
                else:
                    on[i] += 1
                    max_val = max(max_val,on[i])
        while True:
            if count%2 == 0:
                for i in range(a):
                    if b not in on.keys():
                        on[b] = 1
                        max_val = max(max_val,1)
                    else:
                        on[b] += 1
                        max_val = max(max_val,on[b])
                    b += 1
            else:
                b += a
            count += 1
            
            if count > 1000:
                break

    #print(on)
    print(max_val)

main()
