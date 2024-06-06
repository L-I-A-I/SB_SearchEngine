Simple search engine that uses multithreaded indexing to std::map. / Простой поисковой движок использующий многопоточное индексирование в std::map.
Engine threads count adapts to hardware. / Движок адаптирует количество потоков под железо.

Commands: put - puts answers into answers.json, exit - stops program. / put - кладёт ответы в answers.json, exit - закрывает программу.
Periodical indexing is automatically enabled with interval spicified in config.json. / Периодическая индексация запускается автоматически с интервалом указанным в config.json.
Subproject with GoogleTests. / GoogleTests в подпроекте.
config.json, requests.json need to be in the build src directory (their examples in .zip file). / config.json, requests.json должны быть в src папке скомпилированного проекта (их примеры в .zip файле).
nlohmann_json need to be unarchived or installed from github. / nlohmann_json необходимо разархивировать или установить с github.
Json syntax errors outputed to the console. / Ошибки синтаксиса json выводятся в консоль.