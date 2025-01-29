/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instru.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:04:05 by isallali          #+#    #+#             */
/*   Updated: 2025/01/28 17:16:38 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
void    sort_arr(int *arr, int size)
{
    int i;
    int j;
    int swap;

    j = 0;
    while (j < size - 1)
    {
        i = 0;
        while (i < size - j - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                swap = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = arr[i];
            }
            i++;
        }
        j++;
    }
}

int fill_array(t_stack *a)
{
    int *arr;
    int size;
    int i;

    if (!a)
        return (NULL);
    size = stack_len(a);
    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    while(a)
    {
        arr[i++] = a->value;
        a = a->next;
    }
    sort_arr(arr, i);
    return (arr);
}

void    set_index(t_stack **st)
{
    int *arr;
    int size;
    int i;
    t_stack *hold;

    size = stack_len(st);
    if (size == 0)
        return;
    arr = fill_array(st);
    i = 0;
    while (i < size)
    {
        hold = *st;
        while(hold)
        {
            if (arr[i] == hold->value && hold->index == 0)
            {
                hold->index = i + 1;
                break;
            }
            hold = hold->next;
        }
        i++;
    }
    free(arr);
}
