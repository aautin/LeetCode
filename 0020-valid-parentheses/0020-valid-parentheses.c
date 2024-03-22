typedef struct s_stack {
	struct s_stack	*previous;
	char			letter;
}	t_stack;

void	add_node(t_stack **stack, t_stack *node) {
	if (node == NULL)
        return ;
    if (*stack == NULL) {
		*stack = node;
		node->previous = NULL;
	}
	else {
		node->previous = *stack;
		*stack = node;
	}
}

void	remove_node(t_stack **stack) {
	t_stack	*last_node = *stack;
	if ((*stack)->previous) {
		(*stack) = (*stack)->previous;
    }
	else
		(*stack) = NULL;
	free(last_node);
}	


t_stack	*create_node(char letter) {	
	t_stack	*node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);

	node->letter = letter;
	return (node);
}

int match(char old, char new) {
    if (old == '(')
        return (new == ')');
    else if (old  == '{')
        return (new == '}');
    else if (old  == '[')
        return (new == ']');
    return (0);
}

bool	isValid(char* s) {
	t_stack	*stack = NULL;

	while (*s) {
		if (*s == '(' || *s == '[' || *s == '{') {
			add_node(&stack, create_node(*s));
		}
		else if (!stack)
            return (0);
        else if (match(stack->letter, *s))
			remove_node(&stack);
		else
			break ;
		s++;
	}

	if (stack) {
		while (stack)
			remove_node(&stack);
		return (0);
	}
	return (1);
}