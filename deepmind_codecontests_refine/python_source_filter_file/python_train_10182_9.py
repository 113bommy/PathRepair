N=int(input())
ga,sa,ba=map(int,input().split())
gb,sb,bb=map(int,input().split())

check=(gb>ga)+(sb>sa)+(bb>ba)
if check==3:
    donguri=N

    inc=0
    for i in range(0,donguri//ga+1):
        x=(ga<gb)*i
        for j in range(0,donguri//sa+1):
            y=(sa<sb)*j
            if donguri>=x*ga+y*sa:
                z=((donguri-x*ga-y*sa)//ba)*(bb>ba)
                inc=max(inc,x*(gb-ga)+y*(sb-sa)+z*(bb-ba))

    donguri+=inc
    print(donguri)
elif check==0:
    donguri=N
    inc=0
    for i in range(0,donguri//gb+1):
        x=(ga>gb)*i
        for j in range(0,donguri//sb+1):
            y=(sa>sb)*j
            if donguri>=x*gb+y*sb:
                z=((donguri-x*gb-y*sb)//bb)*(ba>bb)
                inc=max(inc,-x*(gb-ga)-y*(sb-sa)-z*(bb-ba))

    donguri+=inc
    print(donguri)

elif check==2:
    donguri=N
    inc=0
    for i in range(0,donguri//ga+1):
        x=(ga<gb)*i
        for j in range(0,donguri//sa+1):
            y=(sa<sb)*j
            if donguri>=x*ga+y*sa:
                z=((donguri-x*ga-y*sa)//ba)*(bb>ba)
                inc=max(inc,x*(gb-ga)+y*(sb-sa)+z*(bb-ba))

    donguri+=inc
    if ga>gb:
        plus=(donguri//gb)*(ga-gb)
        print(donguri+plus)
    elif sa>sb:
        plus=(donguri//sb)*(sa-sb)
        print(donguri+plus)
    elif ba>bb:
        plus=(donguri//bb)*(ba-bb)
        print(donguri+plus)
    else:
        print(donguri)

else:
    donguri=N
    inc=0
    if ga<gb:
        plus=(donguri//ga)*(gb-ga)
        donguri+=plus
        if sa>sb:
            for i in range(0,donguri//sb+1):
                j=(donguri-i*sb)//bb
                inc=max(inc,i*(sa-sb)+j*(ba-bb))
            print(donguri+inc)
        else:
            inc=(donguri//bb)*(ba-bb)
            print(donguri+inc)

    elif sa<sb:
        plus=(donguri//sa)*(sb-sa)
        donguri+=plus
        if ga>gb:
            for i in range(0,donguri//gb+1):
                j=(donguri-i*gb)//bb
                inc=max(inc,i*(ga-gb)+j*(ba-bb))
            print(donguri+inc)
        else:
            inc=(donguri//bb)*(ba-bb)
            print(donguri+inc)
    else:
        plus=(donguri//ba)*(bb-ba)
        donguri+plus
        if ga>gb:
            for i in range(0,donguri//gb+1):
                j=(donguri-i*gb)//sb
                inc=max(inc,i*(ga-gb)+j*(sa-sb))
            print(donguri+inc)
        else:
            inc=(donguri//sb)*(sa-sb)
            print(donguri+inc)
                
