#include "include/cub3d.h"

void	printfparam(s_param param)
{
	int		i = -1;
	int		n = 1;
	/*printf("Resolution : %d %d\n", param.res[0], param.res[1]);
	printf("Text NO : %s\n", param.NO.tx);
	printf("Text SO : %s\n", param.SO.tx);
	printf("Text WE : %s\n", param.WE.tx);
	printf("Text EA : %s\n", param.EA.tx);
	printf("Text SP : %s\n", param.txSP);
	printf("Floor : r%d g%d b%d\n", param.rgbFL[0], param.rgbFL[1], param.rgbFL[2]);
	printf("Roof : r%d g%d b%d\n", param.rgbRO[0], param.rgbRO[1], param.rgbRO[2]);
	while (++i < param.Lmap * param.Hmap)
	{
		printf("%c", param.map[i]);
		if (n % param.Lmap == 0)
			printf("\n");
		n++;
	}
	printf("Lenght's map : %d, Height's map : %d\n", param.Lmap, param.Hmap);*/
	printf("pos x : %f, pos y : %f\n", param.pos[0], param.pos[1]);
}

int main()
{
	s_param param;

	param = (s_param){ 0 };
	param.info = ft_lstnews();
	param.info->next = 0;
	param.saveinfo = param.info;
	param.movespeed = 0.5;
	param.rotspeed = 0.1;
	init_param(&param);
	printfparam(param);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.res[0], param.res[1], "mlx 42");
	ft_get_data_img(&param, &param.NO);
	ft_get_data_img(&param, &param.EA);
	ft_get_data_img(&param, &param.SO);
	ft_get_data_img(&param, &param.WE);
	ft_get_data_img(&param, &param.sprite);
	mlx_expose_hook(param.win_ptr, print, &param);
	mlx_loop(param.mlx_ptr);
}