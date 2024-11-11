b_inp = int(input())
hm_inp = input()
count = 0

hm = list(map(int, hm_inp.split()))

def reverseTime(time, shift):
    time[1] = time[1]-shift
    if(time[1]<0):
        time[0] = time[0]-1

    time[0] = time[0]%12
    time[1] = time[1]%60

    return time

while hm[1]%10 != 7 and hm[0]%10 != 7:
    count+=1
    hm = reverseTime(hm, b_inp)

print(count)
