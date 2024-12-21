1. Calculator (Postfix Evaluation)
Operation: Evaluate postfix expressions.
Data Structure: Stack
Time Complexity: O(n) – Each token is processed once.
2. Todo List
Operations:
Add task.
Mark task as complete.
Display tasks.
Data Structure: Singly Linked List
Time Complexity:
O(1) for adding a task at the head.
O(n) for displaying tasks and marking a task complete (requires traversal).
3. Contact List
Operations:
Add New Contact: Insert contact at the tail of the list.
Add Phone Number to Existing Contact: Search for the contact and add a phone number.
Display Contacts: Show contacts either in original order or reverse (most recently added first).
Search Contact: Find a contact by name.
Delete Contact: Remove a contact.
Data Structure: Doubly Linked List
Time Complexity:
Add New Contact: O(1) – Insertion at the tail.
Add Phone Number: O(n) – Requires searching for the contact by name.
Display Contacts: O(n) – Linear traversal (either from head to tail or tail to head).
Search for Contact: O(n) – Linear search.
Delete Contact: O(n) – Requires searching for the contact, followed by deletion.
4. Quit Application
Operation: Exit the application and free all allocated memory.
Time Complexity: O(n) – Linear time to free the list.
Conclusion
Task Mate is structured to efficiently handle tasks and contacts with dynamic data management. The doubly linked list provides efficient insertion and deletion at both ends, while the singly linked list for tasks allows for straightforward task management. Each feature's time complexity is optimized for the operations it performs, with most list manipulations occurring in O(1) for insertion and O(n) for traversal or search operations.

