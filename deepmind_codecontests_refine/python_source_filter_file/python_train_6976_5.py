def bubble_sort(seq):
    for i in range(len(seq)):
        flag = 0
        for j in range(len(seq)-1,i,-1):
            if seq[j-1][1] > seq[j][1]:
                seq[j-1],seq[j] = seq[j],seq[j-1]
                flag = 1
        if flag == 0: break
    return seq


def selection_sort(seq):
    for i in range(len(seq)):
        mini = i
        for j in range(i+1,len(seq)):
            if seq[mini][1] > seq[j][1]:mini = j
        seq[i],seq[mini] = seq[mini],seq[i]
    return seq



n = int(input())
*seq,= input().split()
seq2 = seq[:]

bl = bubble_sort(seq)
print(bl)
print("Stable")
sl = selection_sort(seq2)
print(sl)
if bl == sl:print("Stable")
else:print("Not stable")

