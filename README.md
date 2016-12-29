int get_next_line(const int fd, char **line);

Le premier paramètre est le file descriptor depuis lequel lire.

• Le second paramètre est l’adresse d’un pointeur sur caractère qui servira à stocker la ligne lue sur le file descriptor.

• la valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est terminée ou bien qu’une erreur est survenue respectivement.
• Votre fonction get_next_line doit renvoyer son resultat sans le ’\n’.

• Un appel en boucle à votre fonction get_next_line permettra donc de lire le texte disponible sur un descripteur de fichier une ligne à la fois jusqu’à la fin du texte, quelque soit la taille du texte en question ou d’une de ses lignes.

• Assurez-vous que votre fonction se comporte bien lorsqu’elle lit depuis un fichier,
depuis l’entrée standard, depuis une redirection, etc.

• Votre fichier get_next_line.h doit au moins contenir le prototype de la fonction get_next_line et une macro permettant de choisir la taille du buffer de lecture de read. Cette valeur sera modifiée en soutenance pour évaluer la robustesse de votre rendu. Cette macro devra impérativement s’appeler BUFF_SIZE. Par exemple :

#define BUFF_SIZE 32
