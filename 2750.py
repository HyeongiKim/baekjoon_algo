def quicksort(s):
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
            elif e > pivot:
                right.append(e)
        return quicksort(left) + [pivot] + quicksort(right)

def merge(left, right):
    n = len(left+right)
    mergedList = []
    while len(mergedList) < n:
        if len(left) == 0:
            mergedList.append(right.pop(0))
        elif len(right) == 0:
            mergedList.append(left.pop(0))
        else:
            mergedList.append(left.pop(0) if left[0] < right[0] else right.pop(0))

    return mergedList

def mergesort(s):
    if len(s) == 0:
        return []
    elif len(s) == 1:
        return s
    else:
        left = s[:len(s)/2]
        right = s[len(s)/2:]
        
        return merge(mergesort(left),mergesort(right))




lines = input()
tempList = []
for i in range(lines):
    tempList.append(input())

#print '\n'.join(str(e) for e in quicksort(tempList))
print '\n'.join(str(e) for e in mergesort(tempList))
