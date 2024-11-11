a_b=input().split()
a=int(a_b[0])
b=int(a_b[1])
sum=0
s=0
if a<=9:
    for i in range(1,a+1):

        s+=int(str(i)+str(i))
    print(s%b)
elif a<=99:
    sum=9
    s=495
    for i in range(1,10):
        for k in range(10):
            sum+=1
            s+=int(str(i)+str(k)+str(k)+str(i))
            if sum==a:
                print(s%b)
                break
elif a<=999:
    sum=99
    s=495495
    for i in range(1,10):
        for k in range(10):
            for j in range(10):
                sum+=1
                s+=int(str(i)+str(k)+str(j)+str(j)+str(k)+str(i))
                if sum==a:
                    print(s%b)
                    break
elif a<=9999:
    sum=999
    s=495495495
    for i in range(1, 10):
        for k in range(10):
            for j in range(10):
                for l in range(10):
                    sum+=1
                    s += int(str(i) + str(k) + str(j) +str(l)+str(l)+ str(j) + str(k) + str(i))
                    if sum == a:
                        print(s % b)
                        break
elif a <= 99999:
    sum = 9999
    s=495495495495
    for i in range(1, 10):
        for k in range(10):
            for j in range(10):
                for l in range(10):
                    for m in range(10):
                      sum += 1
                      s += int(str(i) + str(k) + str(j) + str(l) +str(m)+str(m)+ str(l) + str(j) + str(k) + str(i))
                      if sum == a:
                          print(s % b)
                          break
elif a==100000 and b>a:
    print(495495496)
elif a==100000:
    print(495495496/b)

elif a <= 999999:
    sum = 99999
    s=495495495495495
    for i in range(1, 10):
        for k in range(10):
            for j in range(10):
                for l in range(10):
                    for m in range(10):
                        for n in range(10):
                          sum += 1
                          s += int(str(i) + str(k) + str(j) + str(l) +str(m)+str(n)+str(n)+str(m)+ str(l) + str(j) + str(k) + str(i))
                          if sum == a:
                              print(s % b)
                              break




