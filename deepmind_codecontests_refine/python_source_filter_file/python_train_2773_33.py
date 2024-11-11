"""Jamie loves sleeping. One day, he decides that he needs to wake up at exactly hh: mm. However, he hates waking up, so he wants to make waking up less painful by setting the alarm at a lucky time. He will then press the snooze button every x minutes until hh: mm is reached, and only then he will wake up. He wants to know what is the smallest number of times he needs to press the snooze button.

A time is considered lucky if it contains a digit '7'. For example, 13: 07 and 17: 27 are lucky, while 00: 48 and 21: 34 are not lucky.

Note that it is not necessary that the time set for the alarm and the wake-up time are on the same day. It is guaranteed that there is a lucky time Jamie can set so that he can wake at hh: mm.

Formally, find the smallest possible non-negative integer y such that the time representation of the time x·y minutes before hh: mm contains the digit '7'.

Jamie uses 24-hours clock, so after 23: 59 comes 00: 00.

Input
The first line contains a single integer x (1 ≤ x ≤ 60).

The second line contains two two-digit integers, hh and mm (00 ≤ hh ≤ 23, 00 ≤ mm ≤ 59).

Output
Print the minimum number of times he needs to press the button."""
x=int(input())
l=[int(a) for a in input().split()]
n=0
b=l[1]
if (l[1]-7)%10==0 or (l[0]-7)%10==0:
    print('0')
else:
    t=tuple([a for a in range(421,480)]+[a for a in range(1021,1080)])
    a=60*l[0]+l[1]
    a0=a
    while a>0:
        a=a-x
        n+=1
        if (a-7)%10==0 or t.count(a)!=0:
            break
    if a<=0:
        a=1440+a
        while a>a0:
            a=a-x
            n+=1
            if (a-7)%10==0 or t.count(a)!=0:
                break
    print(n)
