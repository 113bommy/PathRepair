X, Sum, Count = input(), 1, 0
for i in range(1, len(X)):
    if X[i] != X[i - 1]:
        if Sum % 2 == 0:
            Count += 1
        Sum += 1
    else:
        Sum += 1
print(Count)

# Caption: God bless you General Soleimani

#         ---------Hard Revenge---------

#          ****** Rest in Peace ******
