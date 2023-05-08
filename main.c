#include "sudoku.h"

int check_double(int *nums)
{
    int i = 0;
    int k;
    while(nums[i])
    {
        k = 0;
        while(k < i)
            if(nums[i] == nums[k++])
                return(0);
        i++;
    }
    return(1);
}
int is_valid(t_sud *sud)
{
    t_case *temp = sud->list;
    t_case *temp2;
    int *nums = malloc(sizeof(int) * 10);
    nums[9] = 0;
    while(temp)
    {
        int i = 0;
        while(temp->right)
        {
            nums[i++] = temp->number;
            if(temp->number == 0)
            {
                free(nums);
                return(0);
            }
            temp = temp->right;
            if(!temp)
                break;
        }
        if(!check_double(nums))
        {
            free(nums);
            return(0);
        }
        temp = temp->next;
    }
    temp = sud->list;
    while(temp)
    {
        int i = 0;
        temp2 = temp;
        while(i < 9)
        {
            nums[i++] = temp2->number;
            temp2 = temp2->down;
        }
        if(!check_double(nums))
        {
            free(nums);
            return(0);
        }
        temp = temp->right;
    }
    free(nums);
    return(1);
}
void init_texture(t_sud *sud)
{
    sud->img->one = mlx_load_png("./img/1.png");
    sud->img->two = mlx_load_png("./img/2.png");
    sud->img->three = mlx_load_png("./img/3.png");
    sud->img->four = mlx_load_png("./img/4.png");
    sud->img->five = mlx_load_png("./img/5.png");
    sud->img->six = mlx_load_png("./img/6.png");
    sud->img->seven = mlx_load_png("./img/7.png");
    sud->img->eight = mlx_load_png("./img/8.png");
    sud->img->nine = mlx_load_png("./img/9.png");
    sud->img->sel = mlx_load_png("./img/select.png");
    sud->img->backt = mlx_load_png("./img/background.png");
}
void set_nbr(t_sud *sud, int nbr)
{
    t_case *temp = sud->list;
    if(!sud->selected)
        return ;
    while(temp->pos != sud->selected)
        temp = temp->next;
    if(temp->img && !nbr)
        mlx_delete_image(sud->mlx, temp->img);
    if(temp->img)
        mlx_delete_image(sud->mlx, temp->img);
    if(nbr == 1)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->one);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 2)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->two);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 3)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->three);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 4)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->four);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 5)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->five);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 6)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->six);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 7)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->seven);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 8)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->eight);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
    if(nbr == 9)
    {
        temp->img = mlx_new_image(sud->mlx, 80, 80);
        temp->img = mlx_texture_to_image(sud->mlx, sud->img->nine);
        mlx_image_to_window(sud->mlx, temp->img, temp->x, temp->y);
        temp->number = nbr;
    }
}
int is_locked(t_sud *sud, int pos)
{
    int i = 0;
    while(sud->locked[i])
    {
        if(pos == sud->locked[i])
            return(0);
        i++;
    }
    return(1);
}
void controls(void *param)
{
    t_sud *sud = param;
    if(mlx_is_key_down(sud->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(sud->mlx);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_SPACE) && is_locked(sud, sud->selected))
        set_nbr(sud, 0);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_1) && is_locked(sud, sud->selected))
        set_nbr(sud, 1);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_2) && is_locked(sud, sud->selected))
        set_nbr(sud, 2);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_3) && is_locked(sud, sud->selected))
        set_nbr(sud, 3);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_4) && is_locked(sud, sud->selected))
        set_nbr(sud, 4);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_5) && is_locked(sud, sud->selected))
        set_nbr(sud, 5);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_6) && is_locked(sud, sud->selected))
        set_nbr(sud, 6);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_7) && is_locked(sud, sud->selected))
        set_nbr(sud, 7);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_8) && is_locked(sud, sud->selected))
        set_nbr(sud, 8);
    if(mlx_is_key_down(sud->mlx, MLX_KEY_9) && is_locked(sud, sud->selected))
        set_nbr(sud, 9);
}
void mouse(double x, double y, void *param)
{
    t_sud *sud = param;
    sud->x = x;
    sud->y = y;
}
void click(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
    t_sud *sud = param;
    if(button == 0 && action == 1 && sud->x < WIDTH && sud->y < HEIGHT)
    {
        if(sud->img->select)
            mlx_delete_image(sud->mlx, sud->img->select);
        sud->img->select = mlx_new_image(sud->mlx, 100, 100);
        sud->img->select = mlx_texture_to_image(sud->mlx, sud->img->sel);
        mlx_image_to_window(sud->mlx, sud->img->select, sud->x / 100 * 100, sud->y / 100 * 100);
        sud->selected = ((sud->y / 100 + 1) * 10) + (sud->x / 100 + 1);
    }
}
void init_grille(t_sud *sud)
{
    int x = 1;
    int y = 0;
    if(!sud->list)
    {
        sud->list = malloc(sizeof(t_case));
        sud->list->next = NULL;
        sud->list->back = NULL;
        sud->list->pos = 11;
        sud->list->x = 10;
        sud->list->y = 10;
        sud->list->nbr = 0;
    }
    t_case *temp = sud->list;
    while(temp->next)
    {
        temp = temp->next;
        if(x == 8)
        {
            x = 0;
            y++;
        }
        else
            x++;
    }
    t_case *new = malloc(sizeof(t_case));
    temp->next = new;
    new->next = NULL;
    new->back = temp;
    new->pos = (y + 1) * 10 + x + 1;
    new->x = x * 100 + 10;
    new->y = y * 100 + 10;
    new->nbr = 0;
    if(x == 8)
        new->right = NULL;
    if(y == 8)
        new->down = NULL;
}
void find_num(t_case *a, int num, t_sud *sud)
{
    if(num == 1)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->one);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 2)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->two);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 3)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->three);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 4)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->four);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 5)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->five);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 6)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->six);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 7)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->seven);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 8)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->eight);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
    if(num == 9)
    {
        a->img = mlx_new_image(sud->mlx, 80, 80);
        a->img = mlx_texture_to_image(sud->mlx, sud->img->nine);
        mlx_image_to_window(sud->mlx, a->img, a->x, a->y);
    }
}
void init_back(t_sud *sud)
{
    sud->img->back = mlx_new_image(sud->mlx, 900, 900);
    sud->img->back = mlx_texture_to_image(sud->mlx, sud->img->backt);
    mlx_image_to_window(sud->mlx, sud->img->back, 0 ,0);
}
void set_map(t_sud *sud, bool reset)
{
    t_case *temp;
    if(reset)
    {
        temp = sud->list;
        while(temp)
        {
            if(temp->img)
            {
                mlx_delete_image(sud->mlx, temp->img);
                temp->number = 0;
            }
            temp = temp->next;
        }
        mlx_delete_image(sud->mlx, sud->img->back);
    }
    init_back(sud);
    temp = sud->list;
    int l = 0;
    int fd = open("./maps/medium1.txt", O_RDONLY);
    char *buf = malloc(sizeof(char));
    while(read(fd, buf, 1))
    {
        if(buf[0] >= '0' && buf[0] <= '9')
        {
            temp->number = buf[0] - 48;
            temp->nbr = temp->number;
            if(buf[0] != '0')
            {
                find_num(temp, buf[0] - 48, sud);
                sud->locked[l++] = temp->pos;
            }
            temp = temp->next;
        }
    }
    sud->locked[l] = 0;
}
void row(t_case *first)
{
    t_case *temp = first;
    t_case *temp2 = first->next;
    int i = 1;
    while(i++ < 9 && temp2)
    {
        temp->right = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
}
void column(t_case *first)
{
    t_case *temp = first;
    t_case *temp2 = temp;
    int i = 1;
    while(i)
    {
        i = 1;
        while(i < 10)
        {
            temp2 = temp2->next;
            if(!temp2)
                return ;
            i++;
        }
        temp->down = temp2;
        temp = temp2;
    }
}
void init_line(t_sud *sud)
{
    t_case *temp = sud->list;
    int i = 1;
    while(i < 82)
    {
        if(i % 9 == 1)
            row(temp);
        if(i < 10)
            column(temp);
        i++;
        temp = temp->next;
    }
}
void open_solution(t_sud *sud)
{
    t_case *temp = sud->list;
    int i;
    while(temp)
    {
        i = 0;
        while(i++ < 9)
        {
            printf("%d ", temp->nbr);
            temp = temp->next;
        }
        printf("\n");
    }
}
int check(int *nums)
{
    int i = 0;
    int k;
    while(i < 9)
    {
        k = 0;
        while(k < i)
            if(nums[i] == nums[k++] && nums[i])
                return(0);
        i++;
    }
    return(1);
}
int check_ans(t_sud *sud, int row, int column)
{
    t_case *temp = sud->list;
    int *nums = malloc(sizeof(int) * 9);
    int i = 0;
    while(temp->pos / 10 != row)
        temp = temp->next;
    while(temp)
    {
        nums[i++] = temp->nbr;
        temp=temp->right;
    }
    if(!check(nums))
    {
        free(nums);
        return(0);
    }
    temp = sud->list;
    i = 0;
    while(temp->pos % 10 != column)
        temp = temp->next;
    while(temp)
    {
        nums[i++] = temp->nbr;
        temp = temp->down;
    }
    if(!check(nums))
    {
        free(nums);
        return(0);
    }
    free(nums);
    return(1);
}
void make_sol(t_sud *sud)
{
    t_case *temp = sud->list;

    while(temp)
    {
        while(!is_locked(sud, temp->pos))
            temp = temp->next;
        temp->nbr += 1;
        if(check_ans(sud, temp->pos / 10, temp->pos % 10))
            temp = temp->next;
        else
        {
            while(temp->nbr == 9)
            {
                temp->nbr = 0;
                while(!is_locked(sud, temp->back->pos))
                    temp = temp->back;
                temp = temp->back;
            }
        }
    }
}
void correct(mlx_key_data_t keydata, void* param)
{
    t_sud *sud = param;
    if(keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
    {
        if(is_valid(sud))
            printf("congratz sudoku done\n");
        else
            printf("failed, press r to start again\n");
    }
    if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        open_solution(sud);
    if(keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
    {
        set_map(sud, 1);
        make_sol(sud);
    }
}
int main()
{
    int i = 0;
    t_sud *sud = malloc(sizeof(t_sud));
    sud->img = malloc(sizeof(t_img));
    sud->locked = malloc(sizeof(int) * 82);
    sud->list = NULL;
    sud->selected = 0;
    sud->mlx = mlx_init(WIDTH, HEIGHT, "Sudoku", true);
    while(i++ < 80)
        init_grille(sud);
    init_line(sud);
    init_texture(sud);
    set_map(sud, 0);
    make_sol(sud);
    mlx_cursor_hook(sud->mlx, &mouse, sud);
    mlx_mouse_hook(sud->mlx, &click, sud);
    mlx_loop_hook(sud->mlx, &controls, sud);
    mlx_key_hook(sud->mlx, &correct, sud);
    mlx_loop(sud->mlx);
    mlx_terminate(sud->mlx);
return (0);
}