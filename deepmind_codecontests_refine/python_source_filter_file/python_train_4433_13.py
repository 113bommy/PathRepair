def fun(n,s):
    if n % 4 != 0:
        print('===')
        return
    else:
        #count every letter
        letters = {"A":s.count('A'),"C":s.count('C'),"G":s.count('G'),"T":s.count('T')}

        #no letter can be more than n/4 times
        for key in letters:
            if letters[key] > n/4:
                print('===')
                return

        question_marks = [i for i, x in enumerate(s) if x == '?']
        print(question_marks)
        for question_mark in question_marks:
            #print(question_marks)
            for key in letters:
                #print(key)
                if letters[key] < n/4:
                    #print(s[:question_mark+1])
                    #print(s[question_mark+1:])
                    s = s[:question_mark+1].replace('?', key) + s[question_mark+1:]
                    #print(s)
                    letters[key] += 1
                    #print(letters)
                    break
        print(s)


    return

if __name__ == "__main__":
    n = int(input())
    s = input()
    fun(n, s)