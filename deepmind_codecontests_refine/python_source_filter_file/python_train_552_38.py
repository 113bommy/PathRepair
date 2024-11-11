
n,m = map(int, input().split())

bothIdioms = list(tuple(map(int, input().split())) for _ in range(n))


def rankList(bothIdioms):
    def binarySearchInitial(a_list,target):
        if a_list[0]<= a_list[len(a_list)-1]:
            inicio = 0
            final = len(a_list)-1
            result = -1
            while inicio<=final:
                median = int(inicio+(final-inicio)/2)
                if target == a_list[median]:
                    result = median
                    final = median-1
                elif target>a_list[median]:
                    inicio = median + 1
                else:
                    final = median - 1
            return result
        else:
            final = 0
            inicio = len(a_list)-1
            result = -1
            while final<=inicio:
                median = int(final+(inicio-final)/2)
                if target == a_list[median]:
                    result = median
                    inicio = median-1
                elif target<a_list[median]:
                    final = median + 1
                else:
                    inicio = median - 1
            return result


    def binarySearchFinal(a_list,target):
        if a_list[0]<= a_list[len(a_list)-1]:
            inicio = 0
            final = len(a_list)-1
            result = -1
            while inicio<=final:
                median = int(inicio+(final-inicio)/2)
                if target == a_list[median]:
                    result = median
                    inicio = median+1
                elif target>a_list[median]:
                    inicio = median + 1
                else:
                    final = median - 1
            return result
        else:
            final = 0
            inicio = len(a_list)-1
            result = -1
            while final<=inicio:
                median = int(final+(inicio-final)/2)
                if target == a_list[median]:
                    result = median
                    final = median+1
                elif target<a_list[median]:
                    final = median + 1
                else:
                    inicio = median - 1
            return result

    sortedBySecond = sorted(bothIdioms, key=lambda tup: tup[1])
    sortedByFirst = sorted(sortedBySecond, key=lambda tup: tup[0], reverse = True)
    myFirst = sortedByFirst[m-1][0]
    mySecond = sortedByFirst[m-1][1]
    twoList = [list(t) for t in zip(*sortedByFirst)]
    list1 = twoList[0]
    list2 = twoList[1]
    initial_index = binarySearchInitial(list1,myFirst)
    final_index = binarySearchFinal(list1,myFirst)#indice final
    initial_index2 = binarySearchInitial(list2[initial_index:final_index+1],mySecond) + initial_index
    final_index2 = binarySearchFinal(list2[initial_index2:final_index+1],mySecond)+initial_index
    return final_index2-initial_index2 +1

print(rankList(bothIdioms))

