def process_word(word):
    count = [0,0,0,0,0]

    for i in word:
        if i =='a':
            count[0]+=1
        elif i == 'b':
            count[1]+=1
        elif i == 'c':
            count[2]+=1
        elif i == 'd':
            count[3]+=1
        else:
            count[4]+=1
    
    s = sum(count)

    return [2*i-s for i in count]


def process(n, words):
    counts = []

    to_return = [0]*5

    for i in words:
        counts.append(process_word(i))
    

    #print(counts)
    for i in range(5):
        counts.sort(key = lambda x: x[i], reverse = True)
        #print(counts)

        if counts[0][i]<1:
            pass
        else:
            counter = 1

            index = 1

            negative = counts[0][i]

            while(index<n):
                negative+=counts[index][i]
                index+=1
                if negative>0: counter+=1
                else: break 
            to_return[i]=counter 
    
    return max(to_return)


print(process(2, ["baba", "baba"]))







t = int(input())

for i in range(t):
    n = int(input())

    words = []
    for j in range(n):
        words.append(input())
    
    print(process(n, words))