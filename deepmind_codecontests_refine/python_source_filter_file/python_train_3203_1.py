def maximize():
    n = int(input())
    final = ['0']
    seats = list(input())
    seats.append('0')
    final+=seats
    
    answer = "Yes"
    if (n==1 and final[0]=='0'):
        answer ="No"
    else:
        for i in range(n+1):
            if (final[i] == '1' and final[i+1] == '1'):
                answer = "No"
                break
        for j in range(n):
            if (final[j]=='0' and final[j+1]=='0' and final[j+2]=='0'):
                #print(seats[j], seats[j+1], seats[j+2])
                answer = "No"
                break
    return answer

print(maximize())