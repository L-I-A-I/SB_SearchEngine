Simple search engine that uses multithreaded indexing to std::map. / Простой поисковой движок использующий многопоточное индексирование в std::map.
Engine threads count adapts to hardware. / Движок адаптирует количество потоков под железо.

Commands: put - puts answers into answers.json, exit - stops program. / put - кладёт ответ в answers.json, exit - закрывает программу.
Periodical indexing is automatically enabled with interval spicified in config.json. / Периодическая индексация запускается автоматически с интервалом указанным в config.json.
GoogleTests are commented out. / GoogleTests в комментариях.
config.json, requests.json need to be in the build src directory (their examples in .zip file). / config.json, requests.json должны быть в src папке скомпилированного проекта (их примеры в .zip файле).
nlohmann_json need to be unarchived or installed from github. / nlohmann_json необходимо разархивировать или установить с github.
