prost = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1001]
n = int(input())
for i in prost:
    if i>=n:
        m=i
        break
raz = m-n
if n<3:
    print(-1)
elif n==3:
    print(3)
    print(1,2)
    print(2,3)
    print(1,3)
elif n==4:
    print(5)
    print(1,2)
    print(2,3)
    print(3,4)
    print(1,4)
    print(1,3)
elif n==5:
    print(5)
    print(1,2)
    print(2,3)
    print(3,4)
    print(4,5)
    print(1,5)
elif n==6:
    print(7)
    print(1,2)
    print(2,3)
    print(3,4)
    print(4,5)
    print(5,6)
    print(6,1)
    print(2,5)
else:
    print(m)
    arr = []
    for i in range(1,n+1):
        arr.append(i)
    if n%4==3:
        now = arr[:7]
        arr = arr[7:]
        for i in range(7):
            print(now[i],now[(i+1)%7])
        if raz>0:
            print(now[0],now[2])
            raz-=1
        if raz>0:
            print(now[3],now[5])
            raz-=1
        if raz>0:
            print(now[4],now[6])
            raz-=1
        n-=7
    elif n%4==2:
        now=arr[:6]
        arr=arr[6:]
        for i in range(6):
            print(now[i],now[(i+1)%6])
        if raz>0:
            print(now[0],now[2])
            raz-=1
        if raz>0:
            print(now[3],now[5])
            raz-=1
        if raz>0:
            print(now[1],now[4])
            raz-=1
        n-=6
    elif n%4==1:
        now = arr[:5]
        arr=arr[5:]
        for i in range(5):
            print(now[i],now[(i+1)%5])
        if raz>0:
            print(now[1],now[3])
            raz-=1
        if raz>0:
            print(now[2],now[4])
            raz-=1
        n-=5
    while raz>=2:
        now=arr[:4]
        arr=arr[4:]
        for i in range(4):
            print(now[i],now[(i+1)%4])
        print(now[0],now[2])
        print(now[1],now[3])
        raz-=2
    if len(arr)>0:
        now=arr[:4]
        arr=arr[4:]
        for i in range(4):
            print(now[i],now[(i+1)%4])
        if raz>0:
            print(now[0],now[2])
            raz-=1
        if raz>0:
            print(now[1],now[3])
            raz-=1
    while len(arr)>0:
        now=arr[:4]
        arr=arr[4:]
        for i in range(4):
            print(now[i],now[(i+1)%4])

    
    


