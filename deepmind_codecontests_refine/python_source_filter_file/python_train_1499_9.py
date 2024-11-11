n_rounds = 0
names = []
scores = []
table_score = []
index_max_score = 0

def Input():
    global n_rounds, names, scores, table_score, index_max_score

    n_rounds = int(input())

    for index in range(n_rounds):
        temp_1, temp_2 = list(map(str,input().split()))
        names.append(temp_1)
        scores.append(int(temp_2))


def Initialization():
    table_score.append([names[0],scores[0],0]);


def Find_index_name(index):
    global n_rounds, names, scores, table_score, index_max_score

    index_found = -1;
    for index_2 in range(0,len(table_score)):
        if (table_score[index_2][0] == names[index]):
           index_found = index_2;

    return index_found;

def Update_table_score(index,index_found):
    global n_rounds, names, scores, table_score, index_max_score

    if (index_found == -1):
        table_score.append([names[index],scores[index],index])
    else:
        table_score[index_found][1] += scores[index];
        table_score[index_found][2] = index;
def Processing():
    
    global n_rounds, names, scores, table_score, index_max_score

    Initialization() # Step 1: Base

    # Step 2: make table score
    for index in range(1,n_rounds):
        index_found = Find_index_name(index); # Find names[index] on the table_score
        Update_table_score(index,index_found)

    # Step 3: find the max_score
    max_score = max( player[1] for player in table_score)
    index_max_score = n_rounds

    # Step 4: find the name of the player who

    for player in table_score:
        if max_score == player[1]:
            sum_score = 0

            for index in range(n_rounds):
                if names[index] == player[0]:
                    sum_score += scores[index]
                    if sum_score == max_score and index_max_score > index:
                        index_max_score = index

                  
def Output():

    global n_rounds, names, scores, table_score, index_max_score

    print(names[index_max_score])
                      



if __name__ == '__main__':
    Input()
    Processing()
    Output()
