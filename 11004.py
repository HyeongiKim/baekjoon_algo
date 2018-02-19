def k_quicksort(s,k):
    if len(s) == 0:
        return [] 
    
    elif len(s) == 1:
        return s

    else:
        pivot = s[len(s)/2]
        left = []
        right = []

        for e in s:
            if e < pivot:
                left.append(e)
                if len(left) == k-1:
                    return [pivot]
            elif e > pivot:
                right.append(e)
        return k_quicksort(left,k) + [pivot] + k_quicksort(right,k)

n, k = map(int,raw_input().split())
List = map(int,raw_input().split())
print k_quicksort(List,k)[k-1]
#print '\n'.join(str(e) for e in quicksort(tempList))
#print '\n'.join(str(e) for e in mergesort(tempList))
