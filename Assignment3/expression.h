#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "queue.h"

void infix_to_postfix(const char *infixstr, Queue *postfix_queue);
int evaluate_postfix(Queue queue);

#endif // EXPRESSION_H
