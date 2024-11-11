S = input()
A = 'Good'
for i in range(2):
    if S[i] == S[i+1]:
        A = 'Bad'
        
print(A)