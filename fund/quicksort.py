#!/bin/python

#quick_sort = lambda array: array if len(array) <= 1 else quick_sort([item for item in array[1:] if item <= array[0]]) + [array[0]] + quick_sort([item for item in array[1:] if item > array[0]])

def quick_sort(array):
    if len(array) <= 1:
        return array

    list_l = quick_sort([item for item in array[1:] if item <= array[0]])
    list_r = quick_sort([item for item in array[1:] if item > array[0]])
    
    new_list = list_l + [array[0]] + list_r
    return new_list

list_temp = [3,4,5,6,2,1,5,8,4,2,65,8,3,2,6,0]
print (quick_sort(list_temp))

