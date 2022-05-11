#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int ret;
    
    // déclaration du tube
    // il y aura un file descriptor par extrémité du tube :
    //    0 : extrémité en lecture
    //    1 : extrémité en écriture
    int fds[2];

    // création du tube
    // le tube est simultanément créé et ses extrémités ouvertes
    //      comme s'il y avait eu deux "open"
    ret = pipe(fds);
    assert(ret == 0);

    // après un fork, le tube reste en un seul exemplaire, mais
    // les deux extrémités sont dupliquées pour que chaque processus
    // y ait accès.
    // En règle générale, chaque processus ferme une extrémité pour
    // n'utiliser que l'autre
    if (fork() == 0)
    {
        printf("   [fils] je vais récupérer que qu'envoie mon père\n");

        // fermeture de l'extrémité inutile, i.e. celle où on écrit
        close(fds[1]);

        // lecture d'un float
        float f;
        ret = read(fds[0], &f, sizeof(float));
        assert(ret == sizeof(float));
        printf("   [fils] et j'ai reçu %g\n", f);

        // fermeture de l'extriémité qui ne sert plus
        close(fds[0]);
    }
    else
    {
        printf("[père] j'envoie des données à mon fils\n");

        // fermeture de l'extrémité inutile, i.e. celle où on lit
        close(fds[0]);

        // écriture d'un float
        float f = 3.1415926535897932384626433832795028841971;
        printf("[père] Dans une seconde j'envoie le float %g\n", f);
        sleep(1);
        ret = write(fds[1], &f, sizeof(float));
        assert(ret == sizeof(float));

        // fermeture de l'extrémité qui ne sert plus
        close(fds[1]);
        
        // histoire d'être correct
        wait(NULL);
    }

    printf("Chaque processus passe par ici, moi je suis %d\n", getpid());
    return EXIT_SUCCESS;
}
